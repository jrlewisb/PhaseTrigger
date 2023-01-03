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
    setSize (500, 250);
    currentView = &phaserView;
    addAndMakeVisible(&triggerComponent);
    addAndMakeVisible(currentView);
    //addAndMakeVisible(outputSettingsComponent);
    
}

PhaseTriggerAudioProcessorEditor::~PhaseTriggerAudioProcessorEditor()
{
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
