

#pragma once

#include <JuceHeader.h>


class EnvelopeView  : public juce::Component
{
public:
    EnvelopeView()
    {


    }


    
    void paint(juce::Graphics& g) override{
        g.setColour(MyColours::SELECTED_VIEW);
        g.fillRect(getLocalBounds());
        g.drawText("EnvelopeView", 0, 0, getWidth(), getHeight(), juce::Justification(1));
        
    }

    
        
    void resized() override{
        auto bounds = getLocalBounds();
        auto totalWidth = bounds.getWidth();
        auto totalHeight = bounds.getHeight();
            
        waveSelectButtonBounds = bounds.removeFromLeft(totalWidth * 0.1);
            
        linkBounds = bounds.removeFromRight(totalWidth * 0.1);
            
        notchSelectDropdownBounds = bounds.removeFromTop(totalHeight * 0.2);
        envelopeCustomizationBounds = bounds;
    }

    void makeASDREnvelope(){
        
    }


private:
    juce::Rectangle<int> waveSelectButtonBounds;
    juce::Rectangle<int> notchSelectDropdownBounds;
    juce::Rectangle<int> envelopeCustomizationBounds;
    juce::Rectangle<int> linkBounds;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EnvelopeView)
};
