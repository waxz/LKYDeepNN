#ifndef _OutputLayer_hpp_
#define _OutputLayer_hpp_

#include "Layer.hpp"
#include "HiddenLayer.hpp"

class HiddenLayer;

class OutputLayer: public Layer
{
    //順向進入的權重與基底
    protected: vector<vector<double>> intoWeights;
    protected: vector<double> outBiases;

    //前層
    protected: HiddenLayer* previousLayer;

    //活化函數
    private: Activation* activation = NULL;
    public: void SetActivation(Activation*);

    public: ~OutputLayer()
    {
        activation->~Activation();
        if(NULL != activation)
        {
            delete activation;
            activation = NULL;
        }
        cout << "~OutputLayer()" << endl;
    }

    public: void InitializeWeights();

    public: void ForwardPropagation();

    public: void BackPropagation(double , vector<double>);

    public: vector<double> GetOutput();

    public: string ToString(){ return "class OutputLayer";}

    public: void SetPrevLayer(HiddenLayer*);
};

#endif