# 42_fdf

This repository contains the implementation of the FdF project, a 3D wireframe viewer. The project involves creating a graphical representation of a 3D landscape from a 2D file using the MiniLibX library.

# Overview
The FdF (Fil de Fer) project is a graphics programming exercise where you create a 3D wireframe model from a given set of coordinates in a 2D file. The objective is to draw a 3D representation of the map using isometric projection, applying transformations such as translation, rotation, and scaling. The project helps in understanding the fundamentals of computer graphics and handling events in a graphical window.
<div align="center">
    
![pic](https://github.com/mjorgecruz/42_fdf/blob/main/Screenshot%20from%202024-09-23%2016-02-32.png)

</div>
# Features

## Mandatory Part

- 2D to 3D Conversion:
    - Parse a given .fdf file containing 2D coordinates to create a 3D wireframe.
- Isometric Projection:
    - Render the 3D wireframe using isometric projection to provide a clear view of the 3D landscape.
- Graphics Window:
    - Display the wireframe in a window using the MiniLibX library.
    - Close the window and handle key events to exit the program gracefully.
    - Apply color gradients based on altitude to enhance the visual representation of the landscape.

## Bonus Part

- Additional Projections:
    - Implement other projection modes such as parallel and top-down projections.
- Basic Transformations:
    - Implement translation, scaling, and rotation to manipulate the wireframe.
    - Smoothly handle zoom in and out using the mouse scroll wheel.
    - Allow rotation around all three axes (x, y, z) for a better view of the model.

- Multi-Map Support:
    - Add the ability to switch between different .fdf maps loaded into the program.

## How to run

1. Clone repository
    ```bash
    git clone git@github.com:mjorgecruz/42_fdf.git
    ```

2. Go inside project directory and run `make`
    ```bash
    cd 42_fdf
    make
    ```
3. Run `./fdf {PATH_TO_MAP}`.
     ```bash
    ./fdf ./maps/valid/42.fdf 
    ```
