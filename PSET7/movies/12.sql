SELECT movies FROM movies WHERE id IN (SELECT movie_id FROM stars WHERE person_id IN (SELECT id FROM people WHERE name = "Bradley Cooper"))
INTERSECT SELECT movie_id FROM stars WHERE person_id IN (SELECT id FROM people WHERE name = " Jennifer Lawrence")
