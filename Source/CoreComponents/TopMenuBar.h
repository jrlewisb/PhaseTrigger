
#pragma once
#include <JuceHeader.h>
#include "../Components/Reusable/MenuButtonComponent.h"

/*
    This file contains the TopMenuBar, as well as definitions of components that are useful in improving the readability of the TopMenuBar component,
    but not necessarily useful in other places.
 
    TODO:   Investigate setting preset selector struct to private with friend visibility to TopMenuBar, potentially apply this to other similarly structured files
*/

struct PresetSelector : juce::Component //Subcomponent used in TopMenuBar
{
    PresetSelector() :  leftButton("Left", "<"),
                        rightButton("Right", ">"),
                        presetName("Preset Name", "Preset Name")
    {
        leftButton.setButtonText("<");
        rightButton.setButtonText(">");
        presetName.setJustificationType(juce::Justification::centred);
        presetName.setColour(juce::Label::textColourId, MyColours::VIEW_TEXT);
        
        addAndMakeVisible(leftButton);
        addAndMakeVisible(rightButton);
        addAndMakeVisible(presetName);
    }
    
    private:
    void resized() override
    {
        //Set the positions of children
        auto bounds = getLocalBounds();
        auto lButton = bounds.removeFromLeft(bounds.getWidth() * 0.2);
        auto rButton = bounds.removeFromRight(bounds.getWidth() * 0.25);
        auto presetNameBounds = bounds;

        leftButton.setBounds(lButton);
        rightButton.setBounds(rButton);
        presetName.setBounds(presetNameBounds);
        
    }

    void paint (juce::Graphics& g) override
    {
        g.setColour(MyColours::VIEW);
        g.fillRect(getLocalBounds());
    }

    //Member Variables - Child Components
    juce::TextButton leftButton;
    juce::TextButton rightButton;
    juce::Label presetName;
};





struct TopMenuBar : juce::Component
{
    TopMenuBar() :  topSettings("Settings"),
                    phaserButton("Phaser"),
                    envelopeButton("Envelope")
    {   //CONSTRUCTOR
        addAndMakeVisible(topSettings);
        addAndMakeVisible(presetSelector);
        addAndMakeVisible(phaserButton);
        addAndMakeVisible(envelopeButton);
    }

    MenuButtonComponent& getPhaserButton()
    {
        return phaserButton;
    }
    
    MenuButtonComponent& getEnvelopeButton()
    {
        return envelopeButton;
    }

    MenuButtonComponent& getSettingsButton()
    {
        return topSettings;
    }



    void resized() override
    {
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
    
    void paint(juce::Graphics& g) override
    {
        g.setColour(juce::Colours::blue);
        g.fillRect(getLocalBounds());
    }

    private:
    //Members, Sub Components
    MenuButtonComponent topSettings;
    PresetSelector presetSelector;
    MenuButtonComponent phaserButton;
    MenuButtonComponent envelopeButton;
};
