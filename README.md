## OpenGL + Perspective: Why is my model invisible

Often while developing OpenGL applications from scratch, the model becomes invisible and it's hard to understand why.

This application is aimed at solving this issue. It allows to manually set the model position and parameters of the perspective projection matrix.

The resulting point in NDC is displayed as well as the preview.

![Demo of the application](/doc/demo.png?raw=true "OpenGL and parameters window")

### Build & run
**Dependencies:** Qt5, GLUT

Build and run steps:
1. ` $ qmake`
2. ` $ make -j10`
3. ` $ ./why_is_my_model_invisible_opengl`
