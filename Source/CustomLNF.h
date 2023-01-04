#pragma once
#include <JuceHeader.h>
#include "./BinaryBuilderFonts/spacegrotesk.h"

//Declaring namespaces for easy access of colours
namespace MyColours{
const juce::Colour SELECTED_VIEW = juce::Colour(0xff5B5D6B);
const juce::Colour SELECTED_VIEW_DETAIL = juce::Colour(0xff777986);
const juce::Colour VIEW = juce::Colour(0xffD2D4DA);
const juce::Colour VIEW_DETAIL = juce::Colour(0xffB3B5BD);
const juce::Colour VIEW_TEXT = juce::Colour(0xff404252);
const juce::Colour SELECTED_VIEW_TEXT = juce::Colour(0xfff3f4f8);
    
}

//Declaring namespace for fonts for easy access of fonts. There is probably a better way to do both of these things
namespace MyFonts{
const float FONT_MAX = 24.f;
const float FONT_LARGE = 20.f;
const float FONT_MED = 18.f;
const float FONT_SMALL = 16.f;
const float FONT_SMALLER = 14.f;
const float FONT_SMALLEST = 12.f;
}

//Custom Look and Feel for overriding a few methods
struct CustomLNF : juce::LookAndFeel_V4{
    CustomLNF() :
            typeface(
                     juce::Typeface::createSystemTypefaceFor(
                        spacegrotesk::SpaceGroteskMedium_ttf,
                        spacegrotesk::SpaceGroteskMedium_ttfSize)
                     )
    {
        //Setting the font we built using BinaryBuilder to default
        setDefaultSansSerifTypeface(typeface);

        //Setting default textbutton colours
        setColour(juce::TextButton::buttonColourId, MyColours::VIEW);
        setColour(juce::TextButton::buttonOnColourId, MyColours::SELECTED_VIEW);
        setColour(juce::TextButton::textColourOffId, MyColours::VIEW_TEXT);
        setColour(juce::TextButton::textColourOnId, MyColours::SELECTED_VIEW_TEXT);

        //Combobox for some reason sets button outline, so we set that here
        setColour(juce::ComboBox::outlineColourId, MyColours::VIEW_DETAIL);
    }

    juce::Typeface::Ptr getTypefaceForFont(const juce::Font& font) override
    {
        return typeface;
    }

    void drawButtonBackground(juce::Graphics& g, juce::Button& button, const juce::Colour& backgroundColour, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override
    {
        auto cornerSize = 0.25f;
        auto bounds = button.getLocalBounds().toFloat().reduced(0.75f, 0.75f);
        auto baseColour = backgroundColour.withMultipliedSaturation (button.hasKeyboardFocus (true) ? 1.3f : 0.9f)
                                          .withMultipliedAlpha (button.isEnabled() ? 1.0f : 0.5f);

        if (shouldDrawButtonAsDown || shouldDrawButtonAsHighlighted)
            baseColour = baseColour.contrasting (shouldDrawButtonAsDown ? 0.2f : 0.05f);

        g.setColour (baseColour);

        auto flatOnLeft   = button.isConnectedOnLeft();
        auto flatOnRight  = button.isConnectedOnRight();
        auto flatOnTop    = button.isConnectedOnTop();
        auto flatOnBottom = button.isConnectedOnBottom();

        if (flatOnLeft || flatOnRight || flatOnTop || flatOnBottom)
        {
            juce::Path path;
            path.addRoundedRectangle (bounds.getX(), bounds.getY(),
                                      bounds.getWidth(), bounds.getHeight(),
                                      cornerSize, cornerSize,
                                      ! (flatOnLeft  || flatOnTop),
                                      ! (flatOnRight || flatOnTop),
                                      ! (flatOnLeft  || flatOnBottom),
                                      ! (flatOnRight || flatOnBottom));

            g.fillPath (path);

            g.setColour (button.findColour (juce::ComboBox::outlineColourId));
            //g.strokePath (path, PathStrokeType (1.0f));
        }
        else
        {
            g.fillRoundedRectangle (bounds, cornerSize);

            g.setColour (button.findColour (juce::ComboBox::outlineColourId));
            g.drawRoundedRectangle (bounds, cornerSize, 1.0f);
        }
    }

    juce::Font getTextButtonFont(juce::TextButton&, int buttonHeight) override
    {
        return { juce:: jmin (16.0f, buttonHeight * 0.85f), juce::Font::bold };
    }



  
    private:
    juce::Typeface::Ptr typeface;
    juce::Font font = juce::Font(typeface).withHeight(14.0f);
    
};
