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
        int minimumDimension = juce::jmin(getWidth(),getHeight());
        float outerCircleRadius = minimumDimension / 2;
        float circleRadius = minimumDimension / 2.5f;
        
        g.setColour(MyColours::VIEW_DETAIL);
        g.fillEllipse((getWidth()/2) - outerCircleRadius, (getHeight()/2) - outerCircleRadius, 2*outerCircleRadius, 2*outerCircleRadius);
        
        g.setColour(juce::Colours::green);
        g.fillEllipse((getWidth()/2) - circleRadius, (getHeight()/2) - circleRadius, 2*circleRadius, 2*circleRadius);
    }

    void resized() override
    {

    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LEDLight)
};
