/*
  ==============================================================================

    EnvelopeView.h
    Created: 30 Dec 2022 5:03:30pm
    Author:  Joshua Lewis

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class EnvelopeView  : public juce::Component
{
public:
    EnvelopeView()
    {


    }

    ~EnvelopeView() override
    {
    }
    
    void paint(juce::Graphics& g){
        
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


private:
    juce::Rectangle<int> waveSelectButtonBounds;
    juce::Rectangle<int> notchSelectDropdownBounds;
    juce::Rectangle<int> envelopeCustomizationBounds;
    juce::Rectangle<int> linkBounds;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EnvelopeView)
};