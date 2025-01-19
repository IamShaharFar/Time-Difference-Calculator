# Time Difference Calculator

![GitHub last commit](https://img.shields.io/github/last-commit/IamShaharFar/Time-Difference-Calculator)
![GitHub issues](https://img.shields.io/github/issues/IamShaharFar/Time-Difference-Calculator)
![GitHub stars](https://img.shields.io/github/stars/IamShaharFar/Time-Difference-Calculator)
![GitHub license](https://img.shields.io/github/license/IamShaharFar/Time-Difference-Calculator)

🚀 A robust C program for calculating time differences between any two points in history - from ancient times to modern day! Supporting both BC (BCE) and AD (CE) dates, this calculator handles complex time calculations with precision and ease.

> 🌟 If you find this project helpful, consider giving it a star! It helps others discover this tool.

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [System Requirements](#system-requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Technical Details](#technical-details)
- [Testing](#testing)
- [Contributing](#contributing)
- [Support](#support)
- [License](#license)
- [Contact](#contact)

## Overview

Ever wondered how many seconds passed between Julius Caesar crossing the Rubicon and the moon landing? The Time Difference Calculator is your answer! This command-line application precisely calculates time intervals between any two historical dates, handling both BC and AD eras with ease.

Originally developed as part of coursework at The Open University of Israel, this project demonstrates advanced C programming concepts while providing practical utility for historical and scientific calculations.

## Features

✨ Key highlights:
- Support for dates in both BC (BCE) and AD (CE) eras
- Precise calculation of time differences down to the second
- Input validation with detailed error messages
- Output in both total seconds and human-readable format
- Interactive command-line interface
- Robust handling of the BC/AD transition (no year 0)
- Cross-platform compatibility

## System Requirements

📋 Prerequisites:
- GCC compiler
- ANSI C compatible system
- Make utility (for building)
- Unix-like environment (Linux, macOS, etc.)

## Installation

1. Clone the repository:
```bash
git clone https://github.com/IamShaharFar/Time-Difference-Calculator.git
cd time-difference-calculator
```

2. Compile the program:
```bash
make
```

This will create an executable named `timediff`.

## Usage

Run the program:
```bash
./timediff
```

📝 Input format:
- Enter two timestamps when prompted
- Each timestamp requires 6 numbers: `Year Month Day Hour Minute Second`
- For BC dates, use negative years (e.g., -753 for 753 BC)

Example input:
```bash
>> Enter first time (Year Month Day Hour Minute Second): 2023 12 31 23 59 59
>> Enter second time (Year Month Day Hour Minute Second): 2024 1 1 0 0 0
```

🎯 Sample output:
```
First time:  2023 AD, 12/31 23:59:59
Second time: 2024 AD, 01/01 00:00:00
Time difference: 1 seconds
In readable format: 0 years, 0 days, 0 hours, 0 minutes, 1 seconds
```

To exit the program, press Ctrl+D.

## Project Structure

📁 Key components:
- `timediff.c`: Main source code file containing all program logic
- `Makefile`: Build configuration file
- `test_input.txt` and `test_output.txt`: Test cases and expected outputs
- `test[1-3]_screenshot`, `test[1-3]_input.txt`, `test[1-3]_output.txt`: Test documentation

## Technical Details

### Key Components

1. **Time Structure**
```c
typedef struct {
    int year;   /* year (negative for BC) */
    int month;  /* 1-12 */
    int day;    /* 1-31 */
    int hour;   /* 0-23 */
    int minute; /* 0-59 */
    int second; /* 0-59 */
} time;
```

2. **Core Functions**
- `validate_time()`: Validates input time values
- `calculate_seconds()`: Converts time to total seconds
- `time_diff()`: Calculates difference between two timestamps
- `print_formatted_diff_time()`: Formats output in human-readable form

### Input Validation

🛡️ Comprehensive validation includes:
- Valid ranges for all time components
- Special handling of year 0 (invalid)
- Proper month/day combinations
- Complete input format checking

## Testing

🧪 The project includes three test suites with:
- Input test cases (`test[1-3]_input.txt`)
- Expected outputs (`test[1-3]_output.txt`)
- Test execution screenshots (`test[1-3]_screenshot`)

Run tests:
```bash
./timediff < test1_input.txt
```

## Support

⭐ If you find this project useful, please consider:
- Giving it a star on GitHub
- Sharing it with others who might benefit
- Reporting any issues you encounter
- Contributing improvements or suggestions

## License

📝 This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contact

🧑‍💻 Developed by IamShaharFar as a student project at The Open University of Israel.

📫 Get in touch:
- GitHub: [@IamShaharFar](https://github.com/IamShaharFar)

---

### Show Your Support

If this project helped you, give it a ⭐️ and share it with your friends!

```bash
# Clone this repository
git clone https://github.com/IamShaharFar/Time-Difference-Calculator.git
```

Made with ❤️ by IamShaharFar