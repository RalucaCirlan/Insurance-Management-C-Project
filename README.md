# Insurance Management System – C++ OOP Project

A C++ project demonstrating object-oriented programming concepts through an insurance management system.

---

## Overview

This project implements an insurance management system to showcase:

- Class design with constructors, copy constructor, and destructor  
- Dynamic memory management (`new` / `delete`)  
- Operator overloading: `=`, `<<`, `()`, type conversion to `double`  
- Encapsulation with getters and setters  
- “Has-a” relationship: `ValoareAsigurare` manages multiple `Asigurare` objects  

---

## Classes

### Asigurare

Represents an insurance policy with the following features:

- Attributes: `tipAsigurare`, `numeAsigurat`, `sumaAsigurata`, `durata`  
- Static counter for total number of insurance policies  
- Operator overloads for:  
  - Output (`<<`)  
  - Assignment (`=`)  
  - Function call `()` to update insured amount  
  - Conversion to `double`  
- Dynamic memory handling for string attributes  

### ValoareAsigurare

Manages multiple `Asigurare` objects and calculates average insurance value. Demonstrates a "has-a" relationship.

---

## Features

- Display insurance details using `<<` operator  
- Modify policy attributes via setters  
- Calculate and update insured amount using function-call operator  
- Implicit conversion to `double` for insured amount  
- Aggregate multiple insurance policies and compute their average value  

---

## Main Function Demonstration

- Create insurance policies using different constructors  
- Display and modify policies  
- Use operator overloads for calculations and display  
- Demonstrate dynamic memory management  

---

## Skills Demonstrated

- Object-oriented programming in C++  
- Operator overloading  
- Encapsulation and class design  
- Memory management  
- Class relationships ("has-a")  

---


