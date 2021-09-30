data = readmatrix('data.csv');
ranges = data(:,3);      % depth data from CSV
zenith = 90-data(:,2);   % zenith angle of spherical coord
azimuth = data(:,1);     % azimuth angle of spherical coord

% convert from spherical to cartesian
vecs = [ranges.*sind(zenith).*cosd(azimuth) ranges.*sind(zenith).*sind(azimuth) ranges.*cosd(zenith)];
% cancel out noise (pts with distance > 40cm)
things = sqrt(sum(vecs.^2,2)) < 40;
pcshow(pointCloud(vecs(things,:)))