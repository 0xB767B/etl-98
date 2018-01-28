#!/bin/bash

# Todo: This should obviously go into a scons-tool

rm -rf *.gcda *.gcno coverage-report coverage.info tests/*.gcda tests/*.gcno
scons -c
scons check
lcov --capture --no-external --directory . --directory ../include --output-file coverage.info
genhtml coverage.info --css-file solarized-dark.css --output-directory coverage-report

