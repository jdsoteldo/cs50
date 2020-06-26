SELECT name
FROM (SELECT DISTINCT person_id, name
FROM ratings
JOIN people ON directors.person_id = people.id
JOIN directors ON ratings.movie_id = directors.movie_id
WHERE rating >= 9.0);
