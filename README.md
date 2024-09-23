# 42_fdf

This repository contains the implementation of the FdF project, a 3D wireframe viewer. The project involves creating a graphical representation of a 3D landscape from a 2D file using the MiniLibX library. This README provides an overview of the project, including the features implemented in both the mandatory and bonus parts.

The FdF (Fil de Fer) project is a graphics programming exercise where you create a 3D wireframe model from a given set of coordinates in a 2D file. The objective is to draw a 3D representation of the map using isometric projection, applying transformations such as translation, rotation, and scaling. The project helps in understanding the fundamentals of computer graphics and handling events in a graphical window.
Features
Mandatory Part

    2D to 3D Conversion:
        Parse a given .fdf file containing 2D coordinates to create a 3D wireframe.

    Isometric Projection:
        Render the 3D wireframe using isometric projection to provide a clear view of the 3D landscape.

    Basic Transformations:
        Implement translation, scaling, and rotation to manipulate the wireframe.

    Graphics Window:
        Display the wireframe in a window using the MiniLibX library.
        Close the window and handle key events to exit the program gracefully.

Bonus Part

    Additional Projections:
        Implement other projection modes such as parallel and top-down projections.

    Enhanced Controls:
        Smoothly handle zoom in and out using the mouse scroll wheel.
        Allow rotation around all three axes (x, y, z) for a better view of the model.

    Color Gradients:
        Apply color gradients based on altitude to enhance the visual representation of the landscape.

    Dynamic Window Resizing:
        Support for dynamically resizing the window while maintaining the integrity of the wireframe.

    Multi-Map Support:
        Add the ability to switch between different .fdf maps loaded into the program.


Create a wireframe model representation of a 3D landscape by linking various points with line segments (edges).

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
3. Run `./fdf {PATH_TO_MAP}`. The pid of the process should appear on the terminal output.
     ```bash
    ./fdf ./maps/valid/42.fdf 
    ```

Controls

    Arrow Keys: Move the map (pan).
    + / -: Zoom in and out.
    W / A / S / D: Rotate the map around the x and y axes.
    Q / E: Rotate the map around the z-axis.
    1 / 2 / 3: Switch between different projection modes.
    R: Reset the view.
    ESC: Exit the program.
