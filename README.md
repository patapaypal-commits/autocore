# AUTOCORE — Automotive ECU Control & Diagnostics Platform

A Software-in-the-Loop (SIL) simulation of a realistic vehicle
electronic control system written in modern C++17.

## Goal

Demonstrate professional automotive software engineering practices:
modular architecture, layered design, CAN communication, UDS
diagnostics, fault management, and automated testing.

## Status

Under active development — Phase 1.

## Technology Stack

- C++17
- CMake
- GoogleTest
- Linux (Ubuntu 22.04 / WSL2)
- GitHub Actions

## Building

    cmake -S . -B build
    cmake --build build
    cd build && ctest --output-on-failure

## Author

Adipu