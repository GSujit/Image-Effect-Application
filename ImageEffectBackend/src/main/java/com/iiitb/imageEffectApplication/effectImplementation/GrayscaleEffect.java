package com.iiitb.imageEffectApplication.effectImplementation;

import com.iiitb.imageEffectApplication.baseEffects.PhotoEffect;
import com.iiitb.imageEffectApplication.service.LoggingService;
import libraryInterfaces.Pixel;

import static libraryInterfaces.GrayscaleInterface.applyGrayscale;

public class GrayscaleEffect implements PhotoEffect {

    public Pixel[][] apply(Pixel[][] image, String fileName, LoggingService loggingService){

        loggingService.addLog(fileName,"Grayscale","-");

        image = applyGrayscale(image);

        return image;
    }

}
