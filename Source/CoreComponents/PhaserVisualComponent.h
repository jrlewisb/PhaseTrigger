#pragma once
#include <JuceHeader.h>

class PhaserVisualComponent  : public juce::Component
{
    //this class is essentially the visualisation of the phaser settings
    //the core visual of this class is a logarithmic representation of the audible frequency range
    //we will draw a line of a different colour to represent each notch in the phaser
    //the line will be drawn from the centre of the component to the edge of the component

    void paint(juce::Graphics& g) override
    {
        //draw lines from the top of the component to the bottom of the component, spaced logarithmically apart
        //reset the logarithmic spacing at 10hz, 100hz, 1000hz, 10000hz
        //10, 20, 40, 80,
        //160, 320, 640, 1280,
        //2560, 5120, 10240, 20480, 40960
        auto quarterWidth = getWidth() * 0.25f;
        auto offset = getWidth() * 0.088f;
        auto logTo100 = quarterWidth + offset;
        auto logTo1000 = logTo100 + (quarterWidth);
        auto logTo10000 = logTo1000 + (quarterWidth);
        auto logTo100000 = logTo10000 + (quarterWidth);

        g.setColour(MyColours::VIEW_DETAIL);

        //need to figure out how to draw a logarithmic grid
        //drawLogGrid(g, 10.0f, 100000.0f, offset, logTo100000, 3);



    }

    
};
