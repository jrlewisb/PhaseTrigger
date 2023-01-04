/*
  ==============================================================================

    PhaserView.h
    Created: 30 Dec 2022 5:03:47pm
    Author:  Joshua Lewis

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../CoreComponents/PhaserVisualComponent.h"

struct TitledLabel : public juce::Component
{
    TitledLabel(juce::Label* label, juce::String title)
    {
        valueLabel = label;
        valueTitle = title;
        
        valueLabel->setEditable(true);
        valueLabel->setJustificationType(juce::Justification(9));
        //make the text for the valuelabel align top left, just like when we click on the label to edit it
        
        addAndMakeVisible(valueLabel);
    }
    void paint(juce::Graphics& g) override {
        g.setColour(juce::Colours::black);
        g.drawRect(getLocalBounds());
        g.setFont(titleFontSize);
        g.setColour(juce::Colours::white);
        //get the size of the font 

        g.drawText(valueTitle, 0, 0, getWidth(), getHeight(), juce::Justification(9));
        
        
    }
    void resized() override {
        auto bounds = getLocalBounds();
        bounds.removeFromTop(titleFontSize);
        valueLabel->setBounds(bounds);
        
    }
    
    private:
        juce::Label* valueLabel;
        juce::String valueTitle;
        float titleFontSize = 20.0f;
};



class PhaserView  : public juce::Component
{
public:
    PhaserView() :  notchesLabel("Notches","Notches"),
                    centerLabel("Center","Center"),
                    spreadLabel("Spread","Spread"),
                    blendLabel("Blend","Blend"),
                    notchesTitledLabel(&notchesLabel, "Notches"),
                    centerTitledLabel(&centerLabel, "Center"),
                    spreadTitledLabel(&spreadLabel, "Spread"),
                    blendTitledLabel(&blendLabel, "Blend")
    {
        for(TitledLabel* titledLabel : getTitledLabels()){
            //label.setFont();
            addAndMakeVisible(titledLabel);
        }
        addAndMakeVisible(phaserVisualComponent);
        
        

    }

    ~PhaserView() override
    {
    }

    void paint (juce::Graphics& g) override
    {

        g.setColour(MyColours::SELECTED_VIEW);
        g.fillRect(getLocalBounds());

    }

    void resized() override
    {
        auto bounds = getLocalBounds();
        bounds.removeFromTop(getHeight() * 0.1);
        visualBounds = bounds.removeFromTop(bounds.getHeight() * 0.6);
        labelSettingsBounds = bounds;

        phaserVisualComponent.setBounds(visualBounds);


        
        // notchesTitledLabel.setBounds(labelSettingsBounds.removeFromLeft(labelSettingsBounds.getWidth() * 0.25));
        // centerTitledLabel.setBounds(labelSettingsBounds.removeFromLeft(labelSettingsBounds.getWidth() * 0.3333));
        // spreadTitledLabel.setBounds(labelSettingsBounds.removeFromLeft(labelSettingsBounds.getWidth() * 0.5));
        // blendTitledLabel.setBounds(labelSettingsBounds);
    }

private:
    juce::Rectangle<int> visualBounds;
    juce::Rectangle<int> labelSettingsBounds;
    
    juce::Label notchesLabel;
    juce::Label centerLabel;
    juce::Label spreadLabel;
    juce::Label blendLabel;
    
    TitledLabel notchesTitledLabel;
    TitledLabel centerTitledLabel;
    TitledLabel spreadTitledLabel;
    TitledLabel blendTitledLabel;

    PhaserVisualComponent phaserVisualComponent;
    
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PhaserView)
    
    std::vector<TitledLabel*> getTitledLabels(){
        return {
            &notchesTitledLabel,
            &centerTitledLabel,
            &spreadTitledLabel,
            &blendTitledLabel
        };
    }

};
