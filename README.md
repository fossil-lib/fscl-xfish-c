# Fossil XFish - **C**

Fossil Standard Component Libraries (FSCL) by Fossil Logic represent the pinnacle of software development, embodying our commitment to quality, security, and practicality. These meticulously curated libraries serve as the cornerstone for crafting cutting-edge applications, offering a foundation built on excellence in code. With FSCL, Fossil Logic empowers developers to seamlessly integrate standardized components that elevate the overall performance and reliability of digital solutions, setting a new standard for software excellence.

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
    printf("Saving the trained model...\n");
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

## Who is This For?

This guide is designed for developers of all skill levels who want to use the Meson build system for their projects. It assumes basic familiarity with command-line interfaces and project organization.

## Prerequisites

Before getting started, make sure you have the following installed:

- **Meson Build System**: This project relies on Meson. If you don't have Meson installed, visit the official [Meson website](https://mesonbuild.com/Getting-meson.html) for installation instructions.

## Setting up Meson Build

1. **Install Meson**:
   - Follow the installation instructions on the [Meson website](https://mesonbuild.com/Getting-meson.html) for your operating system.

## Setting up, Compiling, Installing, and Running the Project

1. **Create a Wrap File**:

Create a directory named subprojects in the root directory, next create a file named `tscl-xfish-c.wrap` in the `subprojects` directory of your project with the following content:

   ```bash
   # ================ #
   #  FSCL Wrap File. #
   # ================ #
   [wrap-git]
   url = https://github.com/fossil-lib/fscl-xfish-c.git
   revision = main
   
   [provide]
   fscl-xfish-c = fscl_xfish_c_dep
   ```

2. **Integrate Wrap File in Meson Build**:
   ```meson
   project('my_project', 'c',
       version : '0.1',
       default_options : ['warning_level=3'])

   exe = executable('my_project', 'my_project.c',
       dependencies : dependency('fscl-xfish-c'), # add this line
       install : true)

   test('basic', exe)
   ```

3. **Compile the Project**:
   ```bash
   meson setup builddir
   meson compile -C builddir
   ```

## Including the Demo and Running Tests

To run tests, you can use the following options when configuring the build:

- **Running Tests**: Add `-Dwith_test=enabled` when configuring the build.

Example:

```bash
meson setup builddir -Dwith_test=enabled
```

## Contributing

If you're interested in contributing to this project, please consider opening pull requests or creating issues on the [GitHub repository](https://github.com/fossil-lib/fscl-xfish-c).

## Feedback and Support

If you encounter any issues, have questions, or would like to provide feedback, don't hesitate to open an issue on the [GitHub repository](https://github.com/fossil-lib/fscl-xfish-c/issues).

## License

This project is licensed under the [Mozilla Public License](LICENSE).

---

Thank you for choosing this project with the Meson build system. Happy coding and building amazing projects!
