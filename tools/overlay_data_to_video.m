% Code pasted here is just as a reminder.. 

fps_video = 30; % in Hz
fps_data = 8000; % in Hz
duration_video = 30; % in s
number_of_video_frames = fps_video * duration_video;
window_duration = 5; % in s
number_of_datapoints = window_duration * fps_data; % data samples in window_duration seconds

for n = 1:number_of_video_frames 
    subplot(1,2,1);
    imshow(video(n,:,:));
    subplot(1,2,2);
    data_1 = zeros(number_of_datapoints);
    if (n >= (window_duration * fps_video))
        fps_data_1 = (1, (n * fps_data/fps_video) - number_of_datapoints: n * fps_data/fps_video);
        %fps_data_2 = ...
    end
    plot(data_1, data_2) % don't know what data_with_timestamps looks like (what is x and y, set data_1 and data_2 accordingly...)
    pause(1/fps_video);
end