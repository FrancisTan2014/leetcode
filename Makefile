# Makefile-style commands for LeetCode project

.PHONY: help build test test-verbose test-perf clean configure

help:
	@echo "Available commands:"
	@echo "  make build         - Build all problems"
	@echo "  make test          - Run all tests"
	@echo "  make test-verbose  - Run tests with verbose output"
	@echo "  make test-perf     - Run only performance tests"
	@echo "  make clean         - Clean build directory"
	@echo "  make configure     - Configure CMake"
	@echo "  make new PROBLEM=<name> - Create new problem directory"

build:
	@mkdir -p build
	@cd build && cmake .. && $(MAKE) -j

test: build
	@cd build && ctest --output-on-failure

test-verbose: build
	@cd build && ctest --output-on-failure --verbose | grep -E "Test #|PERF|Passed|Failed|Total"

test-perf: build
	@cd build && ctest -R Performance --verbose | grep -E "Test #|PERF|Passed|Failed"

clean:
	@rm -rf build

configure:
	@mkdir -p build
	@cd build && cmake ..

new:
	@if [ -z "$(PROBLEM)" ]; then \
		echo "Usage: make new PROBLEM=0042-problem-name"; \
		exit 1; \
	fi
	@./new_problem.sh $(PROBLEM)
	@echo "Don't forget to rebuild: make build"
