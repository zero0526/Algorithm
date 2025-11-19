CXX := g++
CXXFLAGS := -std=c++17 -O2

# FILE chương trình, mặc định main.cpp
FILE ?= main.cpp
TARGET := $(FILE:.cpp=)

# Tên test file mặc định: main.cpp -> main_test.txt
TEST := $(TARGET)_test.txt

.PHONY: all test test_all clean run

# Compile chương trình
$(TARGET): $(FILE)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(FILE)

# Chạy 1 test file cụ thể
test: $(TARGET)
	@echo "== Running test for $(TARGET) with $(TEST) =="
	@PASS=0; \
	while read -r INPUT && read -r EXPECTED; do \
		INPUT=$$(echo "$$INPUT" | tr -d '\r'); \
		EXPECTED=$$(echo "$$EXPECTED" | tr -d '\r'); \
		echo "$$INPUT" > input.tmp; \
		echo "$$EXPECTED" > expected.tmp; \
		./$(TARGET) < input.tmp > output.tmp; \
		if diff -w -q output.tmp expected.tmp > /dev/null; then \
			PASS=$$(($$PASS+1)); \
			echo "PASS ✔ ($$INPUT)"; \
		else \
			echo "FAIL ✖ ($$INPUT)"; \
			echo "  Expected: $$EXPECTED"; \
			echo "  Got:      $$(cat output.tmp)"; \
		fi; \
	done < $(TEST); \
	rm -f input.tmp expected.tmp output.tmp; \
	echo "Total passed: $$PASS"; \
	if [ $$PASS -gt 1 ]; then echo "More than one test passed!"; fi

# Chạy tất cả test (ở đây chỉ là file tương ứng với FILE)
test_all: test

# Chỉ chạy chương trình
run: $(TARGET)
	@echo "== Running $(TARGET) =="
	./$(TARGET)

# Xoá file build và tmp
clean:
	rm -f $(TARGET) *.tmp
