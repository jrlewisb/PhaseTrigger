
#pragma once
#include <JuceHeader.h>
#include "../Components/MenuButtonComponent.h"

//define the preset selector component
class PresetSelector : Juce:Component {
    PresetSelector() : leftButton("Left", "<"), rightButton("Right", ">"), presetName("Preset Name") {
        
        //Add the sub components
        addAndMakeVisible(leftButton);
        addAndMakeVisible(rightButton);
        addAndMakeVisible(presetName);
    }
    ~PresetSelector() {
    }

    void resized() override {
        //Set the positions of sub components
        auto bounds = getLocalBounds();
        auto lButton = bounds.removeFromLeft(bounds.getWidth() * 0.2);
        auto rButton = bounds.removeFromRight(bounds.getWidth() * 0.25);
        auto presetName = bounds;

        leftButton.setBounds(lButton);
        rightButton.setBounds(rButton);
        presetName.setBounds(presetName);
        
    }

    void paint (juce::Graphics& g) override {
        //Draw the component
    }

    private:
        juce::Button leftButton;
        juce::Button rightButton;
        juce::Label presetName;
}

class TopMenuBar : Juce:Component {

    TopMenuBar() : topSettings("Settings"), presetSelector(), phaserButton("Phaser", "Phaser"), envelopeButton("Envelope", "Envelope") {
        
        addAndMakeVisible(topSettings);
        addAndMakeVisible(presetSelector);
        addAndMakeVisible(phaserButton);
        addAndMakeVisible(envelopeButton);
    }

    juce::Button& getPhaserButton() {
        return &phaserButton;
    }



    void resized() override {
        //Set the positions of sub components
        auto bounds = getLocalBounds();
        auto topSettingsBounds = bounds.removeFromLeft(bounds.getWidth() * 0.2);
        auto presetSelectorBounds =  bounds.removeFromLeft(bounds.getWidth() * 0.5);
        auto phaserButtonBounds = bounds.removeFromLeft(bounds.getWidth() * 0.5);
        auto envelopeButtonBounds = bounds;

        topSettings.setBounds(topSettingsBounds);
        presetSelector.setBounds(presetSelectorBounds);
        phaserButton.setBounds(phaserButtonBounds);
        envelopeButton.setBounds(envelopeButtonBounds);
    }

    private:
        MenuButtonComponent topSettings;
        juce::Component presetSelector;
        MenuButtonComponent phaserButton;
        MenuButtonComponent envelopeButton;

}