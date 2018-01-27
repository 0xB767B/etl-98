#!/bin/bash

# Todo: This should obviously go into a scons-tool

rm -rf *.gcda *.gcno coverage-report coverage.info tests/*.gcda tests/*.gcno
scons -c
scons check
lcov --capture --directory . --output-file coverage.info
genhtml coverage.info --output-directory coverage-report
chromium coverage-report/index.html
