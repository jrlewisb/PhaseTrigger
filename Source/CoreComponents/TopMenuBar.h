
#pragma once
#include <JuceHeader.h>
#include "../Components/MenuButtonComponent.h"

//define the preset selector component
class PresetSelector : public juce::Component {
public:
    PresetSelector() : leftButton("Left", "<"), rightButton("Right", ">"), presetName("Preset Name", "Preset Name") {
        leftButton.setButtonText("<");
        rightButton.setButtonText(">");
        presetName.setJustificationType(juce::Justification::centred);
        presetName.setColour(juce::Label::textColourId, MyColours::VIEW_TEXT);
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
        auto presetNameBounds = bounds;

        leftButton.setBounds(lButton);
        rightButton.setBounds(rButton);
        presetName.setBounds(presetNameBounds);
        
    }

    void paint (juce::Graphics& g) override {
        //Draw the component
        g.setColour(MyColours::VIEW);
        g.fillRect(getLocalBounds());
    }

    private:
        juce::TextButton leftButton;
        juce::TextButton rightButton;
        juce::Label presetName;
};

class TopMenuBar : public juce::Component {
public:
    TopMenuBar() : topSettings("Settings"), phaserButton("Phaser"), envelopeButton("Envelope") {
        
        addAndMakeVisible(topSettings);
        addAndMakeVisible(presetSelector);
        addAndMakeVisible(phaserButton);
        addAndMakeVisible(envelopeButton);
    }

    MenuButtonComponent& getPhaserButton() {
        return phaserButton;
    }
    
    MenuButtonComponent& getEnvelopeButton(){
        return envelopeButton;
    }

    MenuButtonComponent& getSettingsButton() {
        return topSettings;
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
    
    void paint(juce::Graphics& g) override {
        //Draw the component
        g.setColour(juce::Colours::blue);
        g.fillRect(getLocalBounds());
    }

    private:
        MenuButtonComponent topSettings;
        PresetSelector presetSelector;
        MenuButtonComponent phaserButton;
        MenuButtonComponent envelopeButton;

};
