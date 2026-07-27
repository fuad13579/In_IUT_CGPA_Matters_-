# In IUT, CGPA Matters

A modular C project for managing student course results and calculating GPA/CGPA.

## Features

- Add and view students
- Add and view courses
- Add completed or incomplete course results
- Calculate letter grades, GPA, and CGPA
- Calculate semester-wise GPA
- Calculate required GPA for a target CGPA
- Calculate expected CGPA
- Rank students by CGPA

## Project Structure

```text
main.c
modules/
  course.c
  course.h
  courseResult.c
  courseResult.h
  gpa.c
  gpa.h
  student.c
  student.h
tests/
  test_course.c
  test_course_result.c
  test_gpa.c
  test_student.c
```

## Build and Run

### Windows PowerShell

```powershell
gcc -I modules main.c modules/*.c -o calculator.exe
.\calculator.exe
```

### Linux/macOS

```bash
chmod +x make.sh
./make.sh
./calculator.out
```

## Run Tests

### Windows PowerShell

```powershell
gcc -I modules tests/test_course.c modules/course.c -o test_course.exe
.\test_course.exe

gcc -I modules tests/test_course_result.c modules/course.c modules/courseResult.c -o test_course_result.exe
.\test_course_result.exe

gcc -I modules tests/test_gpa.c modules/course.c modules/courseResult.c modules/gpa.c -o test_gpa.exe
.\test_gpa.exe

gcc -I modules tests/test_student.c modules/course.c modules/courseResult.c modules/gpa.c modules/student.c -o test_student.exe
.\test_student.exe
```

### Linux/macOS

```bash
chmod +x test.sh
./test.sh
```
