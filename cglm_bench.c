
#ifdef __APPLE__
    #include <OpenGL/gl.h>
#elif _WIN32
    #include <windows.h>
    #include <GL/gl.h>
#else
    #include <GL/gl.h>
#endif

#include <cglm.h>
#include <stdio.h>

int main(int argc, char** argv)
{

    if (argc < 2)
        return 1;

    int iterate_count = atoi(argv[1]);

    CGLMmat4 view, proj, model, MVP;
    proj = cglmPerspective(45.0f, 4.0f/3.0f, 0.1f, 100.0f);

    CGLMvec3 position, direction, up;
    position  = (CGLMvec3) {3,0,10};
    direction = (CGLMvec3) {0,0,0};
    up        = (CGLMvec3) {0,1,0};

    int i;
    for (i = 0; i < iterate_count; i++)
    {
        position.z -= 1;
        view = cglmLookAt(position, direction, up);
        MVP = cglmMultMat4(cglmMultMat4(proj, view), model);
    }

    return 0;
}
