#ifndef _HiddenLayer_hpp_
#define _HiddenLayer_hpp_

#include "Layer.hpp"
#include "InputLayer.hpp"
#include "OutputLayer.hpp"

#include <memory>

class HiddenLayer: public Layer
{
    friend class OutputLayer;

    //順向進入的權重與基底
    protected: vector<vector<double>> intoWeights;
    protected: vector<double> hiddenBiases;
    
    //前後層
    protected: Layer* previousLayer;
    public: Layer* nextLayer;

    //活化函數
    private: Activation* activation = NULL;
    public: void SetActivation(Activation*);

    public: ~HiddenLayer()
    {
        activation->~Activation();
        if(NULL != activation)
        {
            delete activation;
            activation = NULL;
        }
        cout << "~HiddenLayer()" << endl;
    }

    public: void InitializeWeights();

    public: void ForwardPropagation();

    public: void BackPropagation(double);

    public: vector<double> GetOutput();

    public: string ToString(){ return "class HiddenLayer";} 

    public: void SetNextLayer(Layer*);
    public: void SetPrevLayer(Layer*);
};

#endif