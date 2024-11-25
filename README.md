#CNC Simulator

Overview

The CNC Simulator is a proof-of-concept application for visualizing the cutting paths of a CNC machine. This project processes 3D objects from STL or OBJ files, calculates cutting paths along XZ planes between maximum and minimum Y-coordinates, and visualizes the paths as polylines in an OpenGL window. The tool aims to simulate and optimize the CNC cutting process by accurately representing the material removal path.

Features

Geometry Library: Efficiently stores and manages 3D object data using classes like Triangulation, Triangle, Point, and SurfacePoint.
Path Creator: Generates cutting paths by slicing the object along XZ planes and intersecting triangles with these planes.
OpenGL Visualization: Displays the triangulated object and computed polylines for better path planning.
Support for STL and OBJ Files: Reads 3D object data and converts it into an optimized format for processing.
Edge Intersection Calculation: Accurately computes intersection points for triangles on each plane.

Project Structure

Geometry Library

Triangulation: Stores triangles, a vector of doubles for unique coordinates, and other data to minimize memory usage.
Triangle: Represents a triangle using indices to points stored in the Triangulation class.
Point: Holds indices for the x, y, and z coordinates.
SurfacePoint: Represents a real-world point with x, y, and z coordinates in double format.
Edge: Stores the start and end points (indices) of a triangle's edge.

CNC Simulator

OBJReader & STLReader: Read 3D object data from OBJ and STL files and populate the Triangulation object.
GraphicsSynchronizer: Coordinates data rendering between the computation logic and OpenGL visualization.
Intersector: Calculates intersection points between triangles and XZ planes.
PathCreator: Generates cutting paths by:
Identifying the maximum and minimum Y-coordinates.
Slicing the object at regular intervals along the Y-axis using XZ planes.
Intersecting triangles with each plane.
Sorting intersection points to form loops and polylines.
OpenGLWindow: Renders the triangulated object and cutting paths as visual output.

Usage

Prepare a 3D object in STL or OBJ format.
Load the object into the simulator using the OBJReader or STLReader class.
Run the PathCreator to generate cutting paths.
Visualize the paths in the OpenGLWindow.

Visualization
The simulator displays the 3D object as a set of polylines representing the CNC machine's cutting path. Each polyline corresponds to a slice at a specific Y-coordinate along the XZ plane.
