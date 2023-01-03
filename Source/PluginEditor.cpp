/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "./PluginProcessor.h"
#include "./PluginEditor.h"

//==============================================================================
PhaseTriggerAudioProcessorEditor::PhaseTriggerAudioProcessorEditor (PhaseTriggerAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setLookAndFeel(&customLNF);
    setSize (500, 250);
    currentView = &envelopeView;

    //assign functionality
    topMenuBar.getPhaserButton().addListener(this);
    topMenuBar.getEnvelopeButton().addListener(this);
    
    addAndMakeVisible(topMenuBar);
    addAndMakeVisible(&triggerComponent);
    addAndMakeVisible(currentView);
    addAndMakeVisible(outputSettingsComponent);
    
}

PhaseTriggerAudioProcessorEditor::~PhaseTriggerAudioProcessorEditor()
{
  topMenuBar.getPhaserButton().removeListener(this);
  topMenuBar.getEnvelopeButton().removeListener(this);

}

void PhaseTriggerAudioProcessorEditor::buttonClicked(juce::Button* button)
{
    if (button == &topMenuBar.getPhaserButton())
    {
        topMenuBar.getPhaserButton().setButtonColour(MyColours::SELECTED_VIEW);
        topMenuBar.getEnvelopeButton().setButtonColour(MyColours::VIEW);
        //currentView->setVisible(false);
        currentView = &phaserView;
        currentView->setVisible(true);
    }
    else if (button == &topMenuBar.getEnvelopeButton())
    {
        topMenuBar.getPhaserButton().setButtonColour(MyColours::VIEW);
        topMenuBar.getEnvelopeButton().setButtonColour(MyColours::SELECTED_VIEW);
        //currentView->setVisible(false);
        currentView = &envelopeView;
        currentView->setVisible(true);
    }
}

//==============================================================================
void PhaseTriggerAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    


}

void PhaseTriggerAudioProcessorEditor::resized()
{
    auto bounds = getLocalBounds();
    auto topBounds = bounds.removeFromTop(bounds.getHeight() * 0.15);
    auto midBounds = bounds.removeFromTop(bounds.getHeight() * 0.7);
    auto bottomBounds = bounds;

    //top bar
    topMenuBar.setBounds(topBounds);

    //these will be set visible / invisible based on which of the buttons are pressed in the tab component
    phaserView.setBounds(midBounds);
    envelopeView.setBounds(midBounds);
    //always visible
  
    //bottom layout
    auto triggerBounds = bottomBounds.removeFromLeft(bottomBounds.getWidth() * 0.2);
    triggerComponent.setBounds(triggerBounds);

    outputSettingsComponent.setBounds(bottomBounds);




    
    
}
