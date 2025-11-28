@echo off
cls
.\make\make.exe -f makefile_test clean
.\make\make.exe -f makefile_test all
.\output\p18f4550example.exe