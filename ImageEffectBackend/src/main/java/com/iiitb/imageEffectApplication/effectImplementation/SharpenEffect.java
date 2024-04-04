package com.iiitb.imageEffectApplication.effectImplementation;

import com.iiitb.imageEffectApplication.baseEffects.SingleValueParameterizableEffect;
import com.iiitb.imageEffectApplication.exception.IllegalParameterException;
import com.iiitb.imageEffectApplication.service.LoggingService;
import libraryInterfaces.Pixel;

import static libraryInterfaces.SharpenInterface.applySharpen;

public class SharpenEffect implements SingleValueParameterizableEffect {
    private float amount;

    public void setParameterValue(float parameterValue) throws IllegalParameterException {

        if(parameterValue > 100 || parameterValue < 0){
            throw new IllegalParameterException("Parameter must be in the range 0 - 100");
        }
        else {
            this.amount = parameterValue;
        }

    }

    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){

        loggingService.addLog(fileName,"Sharpen",String.valueOf(this.amount));

        image = applySharpen(image,amount);

        return image;
    }
}
