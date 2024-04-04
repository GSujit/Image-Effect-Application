package com.iiitb.imageEffectApplication.service;

import com.iiitb.imageEffectApplication.model.LogModel;
import org.springframework.stereotype.Service;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;
import java.time.format.DateTimeFormatter;

@Service
public class LoggingService {

    ArrayList<LogModel> logs = new ArrayList<>();
    public void addLog(String fileName, String effectName, String optionValues) {

        LogModel log = new LogModel(LocalDateTime.now().toString(),fileName,effectName,optionValues);
        logs.add(log);

    }

    public List<LogModel> getAllLogs() {

        return logs;

    }

    public List<LogModel> getLogsByEffect(String effectName) {

        ArrayList<LogModel> filtered_by_effects = new ArrayList<>();

        for(LogModel i : logs){
            if(i.getEffectName().equals(effectName))
                filtered_by_effects.add(i);
        }

        return filtered_by_effects;

    }

    public void clearLogs() {

        logs.clear();

    }

    public List<LogModel> getLogsBetweenTimestamps(LocalDateTime startTime, LocalDateTime endTime) {

        ArrayList<LogModel> filtered_by_time = new ArrayList<>();

        String pattern = "yyyy-MM-dd'T'HH:mm:ss.SSSSSSSSS";
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern(pattern);
        String timestamp;

        for(LogModel i : logs){
            timestamp = i.getTimestamp();
            LocalDateTime localDateTime = LocalDateTime.parse(timestamp,formatter);
            if(localDateTime.isBefore(endTime) && localDateTime.isAfter(startTime))
                filtered_by_time.add(i);
        }

        return filtered_by_time;

    }
}