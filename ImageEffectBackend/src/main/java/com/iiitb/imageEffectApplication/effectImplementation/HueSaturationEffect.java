package com.iiitb.imageEffectApplication.effectImplementation;

import com.iiitb.imageEffectApplication.baseEffects.ParameterizableEffect;
import com.iiitb.imageEffectApplication.exception.IllegalParameterException;
import com.iiitb.imageEffectApplication.service.LoggingService;
import libraryInterfaces.Pixel;

import java.util.Objects;

import static libraryInterfaces.HueSaturationInterface.applyHueSaturation;

public class HueSaturationEffect implements ParameterizableEffect {
    private float saturationValue, hueValue;

    public void setParameter(String paramName, float value) throws IllegalParameterException{

        if(paramName.equals("saturation") || paramName.equals("hue")) {
            if (paramName.equals("saturation")) {
                if (saturationValue > 100 || saturationValue < 0) {
                    throw new IllegalParameterException("Saturation value must be in the range 0 - 100");
                }
                else {
                    this.saturationValue = value;
                }
            }
            else if (hueValue > 100 || hueValue < 0){
                throw new IllegalParameterException("Hue value must be in the range 0 - 100");
            }
            else {
                this.hueValue = value;
            }
        }
        else {
            throw new IllegalParameterException("Parameter name must be saturation or hue");
        }
    }

    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){

        loggingService.addLog(fileName, "Hue & Saturation","Saturation: " + this.saturationValue + "\nHue: " + this.hueValue);

        image = applyHueSaturation(image,this.saturationValue,this.hueValue);

        return image;
    }
}
