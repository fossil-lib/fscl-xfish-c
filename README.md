# Fossil XFish - `C`

Step into the future of artificial intelligence with XFish AI by Fossil. This innovative library combines cutting-edge machine learning algorithms with a focus on aquatic environments. Whether you're developing smart aquaculture systems or exploring AI applications in marine science, XFish AI provides the tools and capabilities to make waves in the world of artificial intelligence for aquatic ecosystems.

## Sample Usage

```c
#include <fossil/xfish/jellyfish.h>
#include <fossil/xcore/console.h>

// Define the size of the input and output layers
enum {
    INPUT_SIZE = 2,
    OUTPUT_SIZE = 1
};

int main() {
    // Create a neural network model
    jellyfish_model *model = fscl_jellyfish_create_model(INPUT_SIZE, OUTPUT_SIZE, "demo_model");

    // Add layers to the neural network
    fscl_jellyfish_add_layer(model->network, INPUT_SIZE, 64, ActivationReLU);
    fscl_jellyfish_add_layer(model->network, 64, OUTPUT_SIZE, ActivationSigmoid);

    // Configure training hyperparameters
    fscl_jellyfish_configure_training(model, LossMeanSquaredError, OptimizerGradientDescent, 0.01);

    // Define training data
    float **input_data;  // Populate with training input data
    float **target_data; // Populate with corresponding target data
    int num_samples = 100; // Number of training samples

    // Train the model
    fscl_console_puts("Training the model...");
    fscl_jellyfish_train(model, input_data, target_data, num_samples, 100, 32);

    // Make predictions using the trained model
    fscl_console_puts("Making predictions...");
    float input[INPUT_SIZE] = {0.1, 0.2};  // Sample input
    float *prediction = fscl_jellyfish_predict(model, input);

    // Display the prediction
    fscl_console_out("Prediction: %f\n", prediction[0]);

    // Save the trained model to a file
    fscl_console_puts("Saving the trained model...");
    fscl_jellyfish_save_model(model);

    // Load the saved model from the file
    fscl_console_puts("Loading the saved model...");
    jellyfish_model *loaded_model = fscl_jellyfish_load_model("demo_model");

    // Make predictions using the loaded model
    fscl_console_puts("Making predictions with the loaded model...");
    float loaded_prediction = fscl_jellyfish_predict(loaded_model, input)[0];
    fscl_console_out("Loaded Prediction: %f\n", loaded_prediction);

    // Free the allocated memory for both models
    fscl_jellyfish_erase_model(model);
    fscl_jellyfish_erase_model(loaded_model);

    return 0;
}
```

## Prerequisites

Before getting started, make sure you have the following installed:

- **Meson Build System**: This project relies on Meson. If you don't have Meson installed, visit the official [Meson website](https://mesonbuild.com/Getting-meson.html) for installation instructions.

## Setting up, Compiling, Installing, and Running the Project

**Adding Dependency**:

Create a directory named subprojects in the root directory, next create a file named `fscl-xfish-c.wrap` in the `subprojects` directory of your project with the following content:

   ```ini
   [wrap-git]
   url = https://github.com/fossil-lib/fscl-xfish-c.git
   revision = main
   
   [provide]
   fscl-xfish-c = fscl_xfish_c_dep
   ```

**Integrate Dependency**:
   ```meson
   project('my_project', 'c')

   exe = executable('my_project', 'my_project.c',
       dependencies : dependency('fscl-xfish-c')) # add this line

   test('basic', exe)
   ```

## Including the Demo and Running Tests

To run tests, you can use the following options when configuring the build:

- **Running Tests**: Add `-Dwith_test=enabled` when configuring the build.

Example:

```zsh
meson setup builddir -Dwith_test=enabled
```

## Contributing and Support

If you're interested in contributing to this project, encounter any issues, have questions, or would like to provide feedback, don't hesitate to open an issue or visit the [Fossil Logic Docs](https://fossillogic.com/the-docs) for more information.
