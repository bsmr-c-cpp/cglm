
#ifdef __APPLE__
#include <OpenGL/gl.h>
#elif _WIN32
#include <windows.h>
#include <GL/gl.h>
#else
#include <GL/gl.h>
#endif

#include <cglm.h>
#include <stdlib.h>

int
main(int argc, char** argv) {
    int iterate_count, i;
    CGLMmat42 view, proj, model, MVP, r;
    CGLMvec3 position, direction, up;

    if (argc < 2)
        return 1;

    iterate_count = atoi(argv[1]);

    cglmMat42(0.0f, &model);
    cglmPerspective2(45.0f, 4.0f / 3.0f, 0.1f, 100.0f, &model);

    position = (CGLMvec3){3.0f, 0.0f, 10.0f};
    direction = (CGLMvec3){0.0f, 0.0f, 0.0f};
    up = (CGLMvec3){0.0f, 1.0f, 0.0f};

    for (i = 0; i < iterate_count; i++) {
        position.z -= 1;
        cglmLookAt2(position, direction, up, &view);
        cglmMultMat42(&proj, &view, &r);
        cglmMultMat42(&r, &model, &MVP);
    }

    return 0;
}
