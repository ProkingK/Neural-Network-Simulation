#include "HiddenLayer.h"
#include "HiddenNeuron.h"

HiddenLayer::HiddenLayer(int numNeurons, HiddenNeuron** neurons, std::string activation) : numNeurons(numNeurons), activation(activation)
{
    this->neurons = neurons;
}

//Prints out information about hidden layer

void HiddenLayer::printLayer()
{
    std::cout<< "h:" << numNeurons << ":" << activation <<std::endl;
}

void HiddenLayer::clearLayer()
{
    if (neurons != NULL)
    {
        for (int i = 0; i < numNeurons; i++)
        {
            neurons[i] = 0;
        }
    }
}

void HiddenLayer::setNumNeurons(int numNeurons)
{
    this->numNeurons = numNeurons;
}

//Calls forward function for every neuron in the layer and performs ReLU or Sigmoid calculation

void HiddenLayer::forward(HiddenLayer* prevLayer)
{
    for (int i = 0; i < numNeurons; i++)
    {
        neurons[i]->forward(prevLayer);
    }
    
    if (activation == "relu")
    {
        for (int i = 0; i < numNeurons; i++)
        {
            neurons[i]->activateReLU();
        }
    }
    else if (activation == "sigmoid")
    {
        for (int i = 0; i < numNeurons; i++)
        {
            neurons[i]->activateSigmoid();
        }
    }
}

//Does the same as the forward function but for the first hidden layer

void HiddenLayer::forward(InputLayer* inputLayer)
{
    for (int i = 0; i < numNeurons; i++)
    {
        neurons[i]->forward(inputLayer);
    }
    
    if (activation == "relu")
    {
        for (int i = 0; i < numNeurons; i++)
        {
            neurons[i]->activateReLU();
        }
    }
    else if (activation == "sigmoid")
    {
        for (int i = 0; i < numNeurons; i++)
        {
            neurons[i]->activateSigmoid();
        }
    }
}

void HiddenLayer::setNeurons(HiddenNeuron** neurons)
{
    if (this->neurons != NULL)
    {
        for (int i = 0; i < numNeurons; i++) 
        {
            this->neurons[i] = NULL;
        }
        delete [] this->neurons;
    }

    this->neurons = neurons;
}

int HiddenLayer::getNumNeurons()
{
    return numNeurons;
}

HiddenNeuron** HiddenLayer::getNeurons()
{
    return neurons;
}

HiddenLayer::~HiddenLayer()
{
    for (int i = 0; i < numNeurons; i++) 
    {
        neurons[i] = NULL;
    }
    delete [] neurons;
}

// (;