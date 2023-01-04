#pragma once
#include <JuceHeader.h>

class PhaserVisualComponent  : public juce::Component
{
    //this class is essentially the visualisation of the phaser settings
    //the core visual of this class is a logarithmic representation of the audible frequency range
public:
    PhaserVisualComponent(){
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
                g.drawLine(x, yMargin, x, getHeight() - yMargin, 2.0f);
                g.setColour(MyColours::VIEW_DETAIL);
            }else{
                g.drawLine(x, yMargin, x, getHeight() - yMargin, 1.25f);
            }
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

    }

    private:
    std::vector<int> values;
    std::vector<int> xValues;
    int yMargin;
    int xMargin;
        

    
};
