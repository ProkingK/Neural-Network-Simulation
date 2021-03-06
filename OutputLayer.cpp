#include "OutputLayer.h"
#include "HiddenNeuron.h"

OutputLayer::OutputLayer(int numWeights, double* weights) : numWeights(numWeights)
{
    outputValue = 0;

    this->weights = weights;
}

void OutputLayer::printLayer()
{
    std::cout<< "o:1" <<std::endl;
}

void OutputLayer::clearLayer()
{
    outputValue = 0;
}

void OutputLayer::setsOutputValue(double outputValue)
{
    this->outputValue = outputValue;
}

//Calls forward function for every neuron in the layer and sums all of them for the final value

void OutputLayer::forward(HiddenLayer* lastHiddenLayer)
{
    double total = 0;
    HiddenNeuron** prevNeurons = lastHiddenLayer->getNeurons();

    for (int i = 0; i < numWeights; i++)
    {
        total += prevNeurons[i]->getValue() * weights[i];
    }
     
    outputValue = total;
}

double OutputLayer::getOutputValue()
{
    return outputValue;
}

OutputLayer::~OutputLayer()
{
    for (int i = 0; i < numWeights; i++) 
    {
        weights[i] = 0;
    }
    delete [] weights;
}

// (;