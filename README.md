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
    if (!model) {
        fscl_console_puts("Failed to create the model.");
        return 1;
    }

    // Add layers to the neural network
    fscl_jellyfish_add_layer(model->network, INPUT_SIZE, 64, ActivationReLU);
    fscl_jellyfish_add_layer(model->network, 64, OUTPUT_SIZE, ActivationSigmoid);

    // Configure training hyperparameters
    fscl_jellyfish_configure_training(model, LossMeanSquaredError, OptimizerGradientDescent, 0.01);

    // Generate sample input and target data
    float *sample_input = fscl_jellyfish_generate_random_input(INPUT_SIZE);
    float *sample_target = fscl_jellyfish_generate_random_target(OUTPUT_SIZE);

    // Train the model with the sample data
    fscl_console_puts("Training the model...");
    fscl_jellyfish_train_for_epochs(model, sample_input, sample_target, 1, 100);

    // Evaluate model performance on sample data
    fscl_console_puts("Evaluating the model...");
    fscl_jellyfish_evaluate_model(model, sample_input, sample_target);

    // Save the trained model to a file
    fscl_console_puts("Saving the trained model...");
    fscl_jellyfish_save_model(model);

    // Display model information
    fscl_console_puts("Model Information:");
    fscl_jellyfish_display_model_info(model);

    // Free the allocated memory for the model and sample data
    fscl_jellyfish_erase_model(model);
    fscl_jellyfish_data_erase(sample_input);
    fscl_jellyfish_data_erase(sample_target);

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
