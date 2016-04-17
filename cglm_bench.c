#include <cglm.h>
#include <stdio.h>
#include <time.h>

#define ITERATE_COUNT 20000000 

int main(int argc, char** argv)
{

    time_t start, end;
    double elapsed;
    time(&start);



    CGLMmat4 view, proj, model, MVP;
    proj = cglmPerspective(45.0f, 4.0f/3.0f, 0.1f, 100.0f);

    CGLMvec3 position, direction, up;
    position  = (CGLMvec3) {3,0,10};
    direction = (CGLMvec3) {0,0,0};
    up        = (CGLMvec3) {0,1,0};

    int i;
    for (i = 0; i < ITERATE_COUNT; i++)
    {
        position.z -= 1;
        view = cglmLookAt(position, direction, up);
        MVP = cglmMultMat4(cglmMultMat4(proj, view), model);
    }


    time(&end);
    elapsed = difftime(end, start);
    printf("Benchmark have simulated %d GL view update in %f seconds\n", ITERATE_COUNT, elapsed);
    printf("CGLM can compute a maximum average of %f frames per seconds\n", ITERATE_COUNT / elapsed);

}
