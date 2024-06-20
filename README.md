# FdF (Fil De Fer)

FdF (Fil De Fer) is a graphical project that reads a map file representing a terrain and displays it in a 3D space using isometric projection. This project utilizes the MinilibX graphics library for basic graphical operations.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)

## Introduction

FdF is a project that explores the basics of graphical programming and provides a visual representation of a terrain map using simple 3D graphics techniques. It allows users to manipulate the display through various controls to change perspective, colors, and other visual aspects.

## Features

- **Map Reading**: Reads a map file where each number corresponds to a point in a grid, defining the terrain height.
- **Isometric Projection**: Displays the map in a 3D space using isometric projection, providing a sense of depth.
- **Interactive Controls**: Allows users to interact with the terrain display:
  - Rotate the map.
  - Move the map with the mouse.
  - Change colors with the `C` key.
  - Adjust the z-axis value.
  - Change the projection type with number keys.
  - Zoom in and out.

## Installation

To compile the FdF program, follow these steps:

1. Clone this repository and navigate to the project directory.
   ```bash
   git clone https://github.com/ChristosDurro/fdf.git
   cd fdf
   ```
2. Compile the program using the provided Makefile:

   ```bash
   make
   ```
  
 3. Run the executable:

   ```bash
   ./fdf [map_file]
   ```
