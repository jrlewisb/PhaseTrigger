#pragma once
#include <JuceHeader.h>

class OutputSettingsComponent : public juce::Component
{
    OutputSettingsComponent() {

    }

    void resized() override {

    }

    void paint(juce::Graphics& g) override {
        g.setColour(juce::Colours::grey);
        g.fillRect(getLocalBounds());
        g.setColour(juce::Colours::white);
        g.setFont(20.0f);
        g.drawText("Output Settings", getLocalBounds(), juce::Justification(9));
    }


    
};