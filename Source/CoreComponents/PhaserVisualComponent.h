#pragma once
#include <JuceHeader.h>

class PhaserVisualComponent  : public juce::Component, public juce::AudioProcessorValueTreeState::Listener
{
    //this class is essentially the visualisation of the phaser settings
    //the core visual of this class is a logarithmic representation of the audible frequency range
public:
    PhaserVisualComponent(juce::AudioProcessorValueTreeState& apvts) : apvts(apvts){
        apvts.addParameterListener("NOTCHES", this);
        
        
        for(int i = 1; i < 5; i++){
            for(int j = 1; j < 12; j++){
                int value = j * pow(10, i);
                if(value > 28000){
                    break;
                }else{
                    values.push_back(value);
                }
            }
        }
    }
    
    ~PhaserVisualComponent() override{
        apvts.removeParameterListener("NOTCHES", this);
    }
    
   

    void paint(juce::Graphics& g) override
    {
        g.setColour(MyColours::SELECTED_VIEW.darker().darker());
        g.fillRoundedRectangle(xMargin, 0, getWidth() - 2*xMargin, getHeight(), 2.f);
        g.setColour(MyColours::VIEW_DETAIL);
        for(int i = 0; i < xValues.size(); i++){
            int& x = xValues[i];
            int& val = values[i];
            if(val == 10 || val == 100 || val == 1000 || val == 10000){
                g.setColour(MyColours::VIEW_DETAIL.brighter());
                g.drawLine(x, yMargin, x, getHeight() - yMargin, 1.5f);
                g.setColour(MyColours::VIEW_DETAIL);
            }else{
                g.drawLine(x, yMargin, x, getHeight() - yMargin, 1.0f);
            }
        }
        //now we draw the notches , lets just say each one appears at 10khz/n + (i * 20khz/n)
        //where n is the number of notches and i is the index of the notch
        g.setColour(juce::Colours::green.brighter());

        for(int notchX : notchXValues){
            g.drawLine(notchX, 2*yMargin, notchX, getHeight() - 2*yMargin, 4.f);
        }
        

        



    }
    
    void parameterChanged(const juce::String& parameterID, float newValue) override{
        DBG(newValue);
        if(parameterID == "NOTCHES"){
            calculateNotchXValues(newValue);
        }
        repaint();
        
    }

    void calculateNotchXValues(int numNotches){
        notchXValues.clear();
        for(int i = 0; i < numNotches; i++){
            int x = (log10((10000/numNotches) + (i * 20000 / numNotches)) * (getWidth() / 4.35)) - (getWidth() / 8);
            notchXValues.push_back(x);
        }
    }
    

    void resized() override
    {
        yMargin = getHeight() * 0.1;
        xMargin = getWidth() * 0.03;
        xValues.clear();
        for(int val : values){
            //since values maps 1:1 with xValues index, we can still use our index logic to decide which ones to draw thicker
            xValues.push_back((log10(val) * (getWidth() / 4.35)) - (getWidth() / 8));
        }
        DBG(apvts.getParameter("NOTCHES")->getValue());
        calculateNotchXValues(apvts.getParameter("NOTCHES")->getValue());

    }

    private:
    std::vector<int> values;
    std::vector<int> xValues;
    std::vector<int> notchXValues;
    int yMargin;
    int xMargin;
    
    juce::AudioProcessorValueTreeState& apvts;
        

    
};
