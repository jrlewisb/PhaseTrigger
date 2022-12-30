/*
  ==============================================================================

    LEDLight.h
    Created: 30 Dec 2022 6:01:52pm
    Author:  Joshua Lewis

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class LEDLight  : public juce::Component
{
public:
    LEDLight()
    {

    }

    ~LEDLight() override
    {
    }

    void paint (juce::Graphics& g) override
    {
        g.setColour(juce::Colours::green);
        g.fillEllipse(getX(), getY(), getWidth(), getHeight());
    }

    void resized() override
    {

    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LEDLight)
};
