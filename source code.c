#include <stdio.h>
#include <pthread.h>

#define NUM_STAGES 3
#define NUM_ITEMS 10

// Define a structure to hold data at different stages of the pipeline
typedef struct {
    int data;
    int stage;
} PipelineData;

// Functions to simulate each stage of the pipeline
void stage1(PipelineData *data) {
    data->data += 1;
    data->stage = 1;
}

void stage2(PipelineData *data) {
    data->data *= 2;
    data->stage = 2;
}

void stage3(PipelineData *data) {
    data->data -= 1;
    data->stage = 3;
}

int main() {
    PipelineData data[NUM_ITEMS];

    for (int i = 0; i < NUM_ITEMS; i++) {
        data[i].data = i;
        data[i].stage = 0;
    }

    // Simulate the pipeline by calling each stage in sequence for each data item
    for (int i = 0; i < NUM_ITEMS; i++) {
        stage1(&data[i]);
        stage2(&data[i]);
        stage3(&data[i]);

        printf("Data: %d, Final Stage: %d\n", data[i].data, data[i].stage);
    }

    return 0;
}
