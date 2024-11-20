﻿#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include "../Lab_11.1C/Lab_11.1C.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestForCommaDash
{
    TEST_CLASS(UnitTestForCommaDash)
    {
    public:
        TEST_METHOD(TestCountCommaDashInFile)
        {
            const char* testFile = "test.txt";

            std::ofstream outFile(testFile);
            outFile << "abc, -def\n";
            outFile << "abc, def\n";
            outFile << ", - , - , -\n";
            outFile << "no matches here\n";
            outFile.close();

            int result = countCommaDashInFile(testFile);
            Assert::AreEqual(4, result, L"Помилка у підрахунку груп ', -' у файлі");

            remove(testFile);
        }

        TEST_METHOD(TestFileNotFound)
        {
            const char* testFile = "nonexistent.txt";
            int result = countCommaDashInFile(testFile);
            Assert::AreEqual(0, result, L"Помилка обробки файлу, якого не існує");
        }
    };
}