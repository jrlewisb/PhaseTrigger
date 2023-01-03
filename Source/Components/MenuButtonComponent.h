#pragma once
#include <JuceHeader.h>

class MenuButtonComponent : public juce::TextButton
{
public:
    MenuButtonComponent(juce::String text) 
    {
        setButtonText(text);

    }
    
    void paintButton(juce::Graphics& g, bool isMouseOverButton, bool isButtonDown) override
    {
        g.setColour(buttonColour);
        g.fillRect(getLocalBounds());
        g.setColour(juce::Colours::red);
        g.setFont(20.0f);
        g.drawText(getButtonText(), getLocalBounds(), juce::Justification(9));
    }

    void setButtonFunction(void(*funcToSet)(const juce::MouseEvent& event)){
        this->buttonFunction = funcToSet;
    }

    void setButtonColour(juce::Colour colourToSet){
        this->buttonColour = colourToSet;
    }
    
    void mouseDown(const juce::MouseEvent& event) override
    {
        buttonFunction(event);
    }

    private:
    void(*buttonFunction)(const juce::MouseEvent& event);
    juce::Colour buttonColour = CustomLNF().VIEW;
    juce::Colour textColour = CustomLNF().VIEW_TEXT;
    
};
