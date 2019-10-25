SELECT s.name,
SUM(o.price) AS SUMA
FROM seasons AS s
JOIN tours AS t ON t.id_season=s.id
JOIN offers AS o ON o.id_tour=t.id
GROUP BY s.name
ORDER BY SUMA DESC;

-------

SELECT c.name,
SUM(o.price) AS SUMA
FROM countries AS c
JOIN tours AS t ON t.id_country=c.id
JOIN offers AS o ON o.id_tour=t.id
GROUP BY c.name
ORDER BY SUMA;

--------

SELECT tr.name,
SUM(o.price) AS SUMA
FROM transports AS tr
JOIN tours AS t ON t.id_transport=tr.id
JOIN offers AS o ON o.id_tour=t.id
GROUP BY tr.name
ORDER BY SUMA DESC;

-------

SELECT t.name,
SUM(o.times) AS SUM_TIME
FROM tours AS t
JOIN offers AS o ON o.id_tour=t.id
GROUP BY t.name
ORDER BY SUM_TIME DESC;
