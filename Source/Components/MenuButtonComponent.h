#pragma once
#include <JuceHeader.h>

class MenuButtonComponent : public juce::Button
{
public:
    MenuButtonComponent(juce::String text) : juce::Button(text)
    {
        setButtonText(text);
    }
    
    void paintButton(juce::Graphics& g, bool isMouseOverButton, bool isButtonDown) override
    {
        g.setColour(buttonColour);
        g.fillRect(getLocalBounds());
        g.setColour(textColour);
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
    juce::LookAndFeel_V4 customLNF = CustomLNF();
    juce::Colour buttonColour = customLNF.VIEW;
    juce::Colour textColour = customLNF.VIEW_TEXT;
    
};
