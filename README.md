# HealthCalc-Suite

## Overview

**HealthCalc-Suite** is a C++ program designed to assist users in managing their health metrics by calculating **Body Mass Index (BMI)** and **Basal Metabolic Rate (BMR)**. The program provides detailed insights based on user inputs such as age, weight, height, gender, and activity level. By combining these factors, the tool helps users understand their caloric needs, as well as giving personalized dietary recommendations to help maintain, gain, or lose weight.

The program also generates a detailed report that users can save for future reference. This report includes BMI, daily calorie needs, and recommended macronutrient breakdowns (proteins, fats, and carbohydrates).

## Project Goal

The goal of **HealthCalc-Suite** is to offer users a reliable tool to monitor and manage their health, particularly for those who are interested in maintaining or improving their fitness. The app aims to simplify complex health calculations and provide valuable insights in a user-friendly way.

## Features

- **User-Friendly Input Process**: Users are prompted to enter their personal data step-by-step, including age, weight, height, gender, and activity level.
  
- **BMI and BMR Calculation**: The program calculates BMI and BMR using well-established formulas, helping users to understand their body composition and caloric needs.

- **Personalized Advice**: Based on the user's BMI and activity level, the program offers personalized recommendations regarding diet and caloric intake, ensuring that the advice aligns with their fitness goals.

- **Report Generation**: A text file (`report.txt`) is automatically generated after the calculation, providing a comprehensive breakdown of the user's health data and advice. This file can be saved and shared for future reference.

- **Input Validation**: The program ensures that all user inputs are within realistic ranges to guarantee accurate results.

## Technologies Used

- **Programming Language**: C++
- **Libraries Used**:
  - `<iostream>`: For input/output handling.
  - `<string>`: To manage text strings.
  - `<fstream>`: To create and write the report.
  - `<limits>`: To ensure valid user input.
  - `<cctype>`: To manage character cases (for handling inputs like gender).
