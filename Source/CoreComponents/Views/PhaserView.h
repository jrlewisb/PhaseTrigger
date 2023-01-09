/*
  ==============================================================================

    PhaserView.h
    Created: 30 Dec 2022 5:03:47pm
    Author:  Joshua Lewis

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../../Components/ViewSpecific/PhaserView/PhaserVisualComponent.h"

#include "../../Components/ViewSpecific/PhaserView/PhaserVisualComponent.h"
#include "../../Components/Reusable/MouseLockSlider.h"


struct MouseLockSliderWrapper : public juce::Component{ //internal component for displaying titles above the mouselocksliders, will refactor to its own .h file if needed
    
    MouseLockSliderWrapper(juce::String name, MouseLockSlider& sliderToWrap) : title(name) , slider(sliderToWrap) {
        addAndMakeVisible(slider);
    }
    
    void paint(juce::Graphics& g) override{
        g.setFont(MyFonts::FONT_MED);
        g.drawText(title, getLocalBounds().removeFromTop(getHeight()/2), juce::Justification(17));
    }
    
    void resized() override{
        auto bounds = getLocalBounds();
        slider.setBounds(bounds.removeFromBottom(bounds.getHeight() / 2));
    }
private:
    juce::String title;
    MouseLockSlider& slider;
    
    /*
     Unused for now, will introduce if we need better size control for the components
    float minTitleSize;
    float minControlBounds;
    float fontSize;
    
    juce::Rectangle<int> titleBounds;
    juce::Rectangle<int> controlBounds;
     */
};



class PhaserView  : public juce::Component
{
    //looking at the initializer list, private members and addAndMakeVisible, in the future lets look into condensing this logic into a class so we can
    //avoid lots of similar code when performing this process
public:
    PhaserView(juce::AudioProcessorValueTreeState& apvts) : notchesMouseLockSliderWrapper("Notches", notchesMouseLockSlider) , 
                                                            frequencyMouseLockSliderWrapper("Frequency", frequencyMouseLockSlider),
                                                            depthMouseLockSliderWrapper("Depth", depthMouseLockSlider),
                                                            notchesAttachment(apvts, "NOTCHES", notchesMouseLockSlider), 
                                                            frequencyAttachment(apvts, "FREQUENCY", frequencyMouseLockSlider),
                                                            depthAttachment(apvts, "DEPTH", depthMouseLockSlider),
                                                            phaserVisualComponent(apvts)
    {
        
        addAndMakeVisible(phaserVisualComponent);
        addAndMakeVisible(notchesMouseLockSliderWrapper);
        addAndMakeVisible(frequencyMouseLockSliderWrapper);
        addAndMakeVisible(depthMouseLockSliderWrapper);
        

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
        controlBounds = bounds;
        
        int controlMarginY = controlBounds.getHeight() * 0.1;
        controlBounds.removeFromBottom(controlMarginY);
        
        int controlMarginX = controlBounds.getWidth() * 0.05;
        controlBounds.removeFromLeft(controlMarginX);
        controlBounds.removeFromRight(controlMarginX);
        
        //set the bounds for each control, there should be 4 all up
        int numberOfControls = 4;
        int controlWidth = controlBounds.getWidth() / numberOfControls;
        auto notchesBounds = controlBounds.removeFromLeft(controlWidth);

        phaserVisualComponent.setBounds(visualBounds);

        notchesMouseLockSliderWrapper.setBounds(notchesBounds);
        frequencyMouseLockSliderWrapper.setBounds(controlBounds.removeFromLeft(controlWidth));
        depthMouseLockSliderWrapper.setBounds(controlBounds.removeFromLeft(controlWidth));
    }

    juce::Slider& getNotchesSlider(){
        return notchesMouseLockSlider;
    }



private:
    juce::Rectangle<int> visualBounds;
    juce::Rectangle<int> controlBounds;
    
    MouseLockSlider notchesMouseLockSlider;
    MouseLockSlider frequencyMouseLockSlider;
    MouseLockSlider depthMouseLockSlider;
    

    MouseLockSliderWrapper notchesMouseLockSliderWrapper;
    MouseLockSliderWrapper frequencyMouseLockSliderWrapper;
    MouseLockSliderWrapper depthMouseLockSliderWrapper;


    juce::AudioProcessorValueTreeState::SliderAttachment notchesAttachment;
    juce::AudioProcessorValueTreeState::SliderAttachment frequencyAttachment;
    juce::AudioProcessorValueTreeState::SliderAttachment depthAttachment;

    PhaserVisualComponent phaserVisualComponent;
    
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PhaserView)
    
   

};
