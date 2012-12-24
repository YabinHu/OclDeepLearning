//===- ocldl/NeuralNetwork.h ------------ Class NeuralNetwork ---*- C++ -*-===//
//
// Author: Yabin Hu (yabin.hwu@gmail.com)
//
//===----------------------------------------------------------------------===//
//
// This header defines class NeuralNetwork.
//
//===----------------------------------------------------------------------===//

#ifndef OCLDL_NEURALNETWORK_H
#define OCLDL_NEURALNETWORK_H

#include <vector>

namespace ocldl {

class NeuralNetwork {
private:

public:
  NeuralNetwork() { }
  virtual ~NeuralNetwork();

  /// @brief Train the network.
  ///
  /// @param Input         Inputs of the training examples.
  /// @param TargetOutput  Target outputs of the training examples.
  void train(const std::vector<double>& Input,
             const std::vector<double>& TargetOutput);

  /// @brief Get the mean squared error.
  ///
  /// @return Value of the mean squared error.
  double getMSE() const;
};

} // End ocldl namespace
#endif /* OCLDL_NEURALNETWORK_H */
