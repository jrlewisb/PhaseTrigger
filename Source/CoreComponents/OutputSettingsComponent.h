#pragma once
#include <JuceHeader.h>

class OutputSettingsComponent : public juce::Component
{
public:
    OutputSettingsComponent() {

    }

    void resized() override {

    }

    void paint(juce::Graphics& g) override {
        g.setColour(MyColours::SELECTED_VIEW);
        g.fillRect(getLocalBounds());
        g.setColour(MyColours::SELECTED_VIEW_TEXT);
        g.setFont(20.0f);
        g.drawText("Output Settings", getLocalBounds(), juce::Justification(36));
    }


    
};
